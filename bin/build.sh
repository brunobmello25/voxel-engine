COMPILER="bear -- c++"

mkdir -p ./target/

PROJECT_ROOT=$(pwd)
pushd ./target/
$COMPILER ../sauce/linux_main.cpp -I${PROJECT_ROOT}/sauce/glad/include `pkg-config sdl3 --cflags --libs` -o linux_app
popd

echo "Build complete. Executable is located at ./target/linux_app"
