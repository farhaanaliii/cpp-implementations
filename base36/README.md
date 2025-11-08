# Base36 Encoding

Base36 encoding uses 0-9 and A-Z, providing a compact alphanumeric representation.

## Usage

```cpp
#include "base36.h"
#include <iostream>

int main(){
    std::string text = "Hi";
    
    std::string encoded = base36_encode(text);
    std::cout << "Encoded: " << encoded << std::endl;
    // Output: 28 2T
    
    std::string decoded = base36_decode(encoded);
    std::cout << "Decoded: " << decoded << std::endl;
    // Output: Hi
    
    return 0;
}
```

## Features
- Uses 0-9, A-Z characters (36 total)
- Case-insensitive decoding
- Space-separated values
- Common for short IDs and URLs
- Compact representation
