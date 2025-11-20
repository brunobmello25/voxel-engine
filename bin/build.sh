COMPILER="bear -- c++"

mkdir -p ./target/

pushd ./target/
$COMPILER ../sauce/linux_main.cpp -o linux_app
popd

echo "Build complete. Executable is located at ./target/linux_app"
