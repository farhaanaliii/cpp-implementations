#include <string>
#include <sstream>

std::string base10_encode(const std::string &text){
	if(text.empty()) return "";
	
	std::ostringstream oss;
	
	for(size_t i = 0; i < text.length(); i++){
        if(i > 0) oss << " ";
        oss << (int)(unsigned char)text[i];
	}
	
	return oss.str();
}

std::string base10_decode(const std::string &encoded){
    if(encoded.empty()) return "";
    
    std::string decoded_str;
    std::istringstream iss(encoded);
    int value;
    
    while(iss >> value){
        decoded_str += (char)value;
    }

    return decoded_str;
}
