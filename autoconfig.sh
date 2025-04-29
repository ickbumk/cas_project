BUILD_TYPE=${1:-Release}
CXX_COMPILER=${2:-g++}

PROJECT_DIR=${3:-$(pwd)}

# Check if OpenCV is installed
if ! pkg-config --exists opencv4; then
    echo "Installing OpenCV..."
    sudo apt update
    cd ~
    git clone https://github.com/opencv/opencv.git
    cd opencv
    git checkout 4.x  # Check out the latest 4.x branch
    mkdir build
    cd build
    cmake .. -DOPENCV_GENERATE_PKGCONFIG=ON
    make -j$(nproc)  # This will use multiple cores to speed up the compilation
    sudo make install

else
    echo "OpenCV already installed."
fi

cd "$PROJECT_DIR" || { echo "Error: Could not navigate to $PROJECT_DIR"; exit 1; }

if [ ! -d ../Catch2-install ]; then
    git clone https://github.com/catchorg/Catch2 ../Catch2
    rm -rf ../build/Catch2
    cmake -S ../Catch2 -B ../build/Catch2 \
        -DBUILD_TESTING=OFF \
        -DCMAKE_INSTALL_PREFIX=../Catch2-install/
    cmake --build ../build/Catch2 -j$(nproc) --target install
fi


cmake -S . -B ./build \
    -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
    -DCatch2_DIR=../Catch2-install/lib/cmake/Catch2 \
    -DCMAKE_CXX_COMPILER=$CXX_COMPILER
cmake --build ./build -j$(nproc)