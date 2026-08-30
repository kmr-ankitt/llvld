#include "document_element.h"
#include <iostream>

TextElement::TextElement(const std::string& text) {
    this->text = text;
}

const std::string TextElement::getText() const {
  return this->text;
}

void TextElement::render() {
  std::cout << "Rendering text: " << this->text << std::endl;
}