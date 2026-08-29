#include "document_element.h"
#include <iostream>

void TextElement::render() {
  std::cout << "Rendering text: " << this->text << std::endl;
}
