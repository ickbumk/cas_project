BUILD_TYPE=${1:-Release}
CXX_COMPILER=${2:-g++}

if [ ! -d ../Catch2-install ]; then
    git clone https://github.com/catchorg/Catch2 ../Catch2
    rm -rf ../build/Catch2
    cmake -S ../Catch2 -B ../build/Catch2 \
        -DBUILD_TESTING=OFF \
        -DCATCH2_INSTALL_CMAKE_FILES=ON \  # Enable CMake install files
        -DCMAKE_INSTALL_PREFIX=../Catch2-install/
    cmake --build ../build/Catch2 -j$(nproc) --target install
fi

cmake -S . -B ./build \
    -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
    -DCatch2_ROOT=../Catch2-install \
    -DCMAKE_CXX_COMPILER=$CXX_COMPILER
cmake --build ./build -j$(nproc)
