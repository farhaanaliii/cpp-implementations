# Base32 Encoding

Base32 encoding uses A-Z and 2-7 characters, making it case-insensitive and URL-safe.

## Usage

```cpp
#include "base32.h"
#include <iostream>

int main(){
    std::string text = "Hello";
    
    std::string encoded = base32_encode(text);
    std::cout << "Encoded: " << encoded << std::endl;
    // Output: JBSWY3DP
    
    std::string decoded = base32_decode(encoded);
    std::cout << "Decoded: " << decoded << std::endl;
    // Output: Hello
    
    return 0;
}
```

## Features
- Uses A-Z, 2-7 characters (32 total)
- Case-insensitive
- 5-bit chunks
- Padding with '=' to multiples of 8
- Common in TOTP codes and compact identifiers
- O(1) character lookup
