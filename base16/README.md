# Base16 (Hexadecimal) Encoding

Hexadecimal encoding uses 0-9 and A-F to represent data in base 16 format.

## Usage

```cpp
#include "base16.h"
#include <iostream>

int main(){
    std::string text = "Hello";
    
    std::string encoded = base16_encode(text);
    std::cout << "Encoded: " << encoded << std::endl;
    // Output: 48656C6C6F
    
    std::string decoded = base16_decode(encoded);
    std::cout << "Decoded: " << decoded << std::endl;
    // Output: Hello
    
    return 0;
}
```

## Features
- Uses 0-9, A-F characters
- Case-insensitive decoding
- 2 hex digits per byte
- Direct nibble manipulation for efficiency
- Common in programming and memory dumps
