#include "document_persistence.h"
#include <fstream>
#include <stdexcept>

void DocumentPersistenceIntoFile::save(DocumentElement &data) {
  std::ofstream outFile("document.txt");

  if (!outFile) {
    throw std::runtime_error("Unable to open file");
  }

  if (auto *text = dynamic_cast<TextElement *>(&data)) {
    outFile << "text\n";
    outFile << text->getText();
  } else if (auto *image = dynamic_cast<ImageElement *>(&data)) {
    outFile << "image\n";
    outFile << image->getImagePath();
  } else {
    throw std::runtime_error("Unknown DocumentElement type");
  }
}
