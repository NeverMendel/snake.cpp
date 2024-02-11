FROM ubuntu:22.04

# Install dependencies

RUN apt update && apt install -y \
  build-essential \
  curl \
  git \
  unzip \
  wget

# Install Bazel
RUN BAZEL_VERSION=7.0.2 && \
    BAZEL_ARCH=$(arch | sed s/aarch64/arm64/) && \
    wget -O /bin/bazel https://github.com/bazelbuild/bazel/releases/download/${BAZEL_VERSION}/bazel-${BAZEL_VERSION}-linux-${BAZEL_ARCH} && \
    chmod +x /bin/bazel

# Install Buildifier
RUN BUILDIFIER_VERSION=v6.4.0 && \
    BUILDIFIER_ARCH=$(arch | sed s/aarch64/arm64/ | sed s/x86_64/amd64/) && \
    wget -O /bin/buildifier https://github.com/bazelbuild/buildtools/releases/download/${BUILDIFIER_VERSION}/buildifier-linux-${BUILDIFIER_ARCH} && \
    chmod +x /bin/buildifier

# Install clang-format
RUN LLVM_VERSION=18 && \
    wget https://apt.llvm.org/llvm.sh && \
    chmod +x llvm.sh && \
    ./llvm.sh ${LLVM_VERSION} && \
    apt install -y clang-format-${LLVM_VERSION}

# Check versions
RUN bazel version
RUN buildifier --version
RUN clang-format-${LLVM_VERSION} --version
