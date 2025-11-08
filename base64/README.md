# Base64 Encoding

Base64 encoding is the standard method for encoding binary data as ASCII text, widely used on the web.

## Usage

```cpp
#include "base64.h"
#include <iostream>

int main(){
    std::string text = "Hello";
    
    std::string encoded = base64_encode(text);
    std::cout << "Encoded: " << encoded << std::endl;
    // Output: SGVsbG8=
    
    std::string decoded = base64_decode(encoded);
    std::cout << "Decoded: " << decoded << std::endl;
    // Output: Hello
    
    return 0;
}
```

## Features
- Uses A-Z, a-z, 0-9, +, / characters (64 total)
- 6-bit chunks
- Padding with '=' to multiples of 4
- Standard encoding for web and email
- Binary to text conversion
- O(1) character lookup
