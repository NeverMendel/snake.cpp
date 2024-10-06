FROM ubuntu:24.04

# Install dependencies
RUN apt update && apt install -y \
  build-essential \
  curl \
  git \
  unzip \
  wget \
  lsb-release \
  software-properties-common \
  gnupg

# Install ncurses
RUN apt install -y \
    libncurses5-dev \
    libncursesw5-dev

# Install Bazelisk
RUN BAZELISK_VERSION=v1.19.0 && \
    BAZELISK_ARCH=$(arch | sed s/aarch64/arm64/) && \
    wget -O /bin/bazel https://github.com/bazelbuild/bazelisk/releases/download/${BAZELISK_VERSION}/bazelisk-linux-${BAZELISK_ARCH}
    chmod +x /bin/bazel

# Install clang-format
RUN wget https://apt.llvm.org/llvm.sh && \
    chmod +x llvm.sh && \
    ./llvm.sh 18 && \
    apt install -y clang-format-18

# Check versions
RUN bazel version
RUN buildifier --version
RUN clang-format-18 --version
