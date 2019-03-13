# Step 1: remove old build
rm -rf build_test
echo "Removed old build foler."

# Step 2: create new build folder
mkdir -p build_test
cd build 
cmake -DCMAKE_BUILD_TYPE=Release -DLOW_MEMORY_NODE=ON ..
make -j$(nproc) beowulfd
make -j$(nproc) cli_wallet
cd ..
echo "Built complete..."

