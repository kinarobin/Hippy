FROM centos

ENV PATH="/opt/gradle-7.3/bin:/opt/depot_tools:${PATH}" JAVA_HOME=/usr/lib/jvm/jre ANDROID_SDK_ROOT=/opt/sdk-root ANDROID_NDK_HOME=/opt/sdk-root/ndk/23.1.7779620/

RUN \
cd \tmp && \
yum -y install java-1.8.0-openjdk-devel git git-lfs unzip python3 python2 pkg-config bzip2 glibc-devel.i686 libstdc++-devel.i686 ncurses-compat-libs libatomic.so.1 && \
yum clean all && \
ln -fs /usr/bin/python2.7 /usr/bin/python && \
git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git /opt/depot_tools && \
/opt/depot_tools/gclient && \
curl -O https://downloads.gradle-dn.com/distributions/gradle-7.3-bin.zip && \
unzip -d /opt gradle-7.3-bin.zip && \
curl -O https://dl.google.com/android/repository/commandlinetools-linux-7583922_latest.zip && \
unzip -d /opt commandlinetools-linux-7583922_latest.zip && \
yes | /opt/cmdline-tools/bin/sdkmanager --sdk_root=$ANDROID_SDK_ROOT --licenses && \
/opt/cmdline-tools/bin/sdkmanager --sdk_root=$ANDROID_SDK_ROOT --install "ndk;23.1.7779620" "cmake;3.10.2.4988404" "build-tools;30.0.2" "platforms;android-30" && \
rm -rf /tmp && mkdir /tmp

RUN \
cd \tmp && \
git clone https://github.com/Tencent/Hippy --depth 1 -b master && \
cd Hippy/examples/android-demo && \
gradle assemblerelease && \
rm -rf /tmp && mkdir /tmp
