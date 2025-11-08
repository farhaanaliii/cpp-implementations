# Base Encoding Tests

Google Test suite for all base encoding implementations.

## Build and Run

```bash
cd tests
cmake -S . -B build
cmake --build build
cd build
ctest --output-on-failure
```

Or run the test executable directly:
```bash
./build/base_encoding_tests
```

## Test Coverage

Each base encoding has tests for:
- Basic encoding/decoding
- Empty strings
- Round-trip conversion
- Invalid input handling
- Edge cases specific to each encoding
