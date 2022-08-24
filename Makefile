wasm:
	cd wasm-build && emcmake cmake .. && cmake --build .
	node --experimental-wasm-threads --experimental-wasm-bulk-memory ./wasm-build/hello_cmake.js	

