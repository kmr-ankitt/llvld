#include "document_persistence.h"
#include <fstream>
#include <stdexcept>

void DocumentPersistenceIntoFile::save(const DocumentModel &doc) {
  std::ofstream outFile("document.txt");

  if (!outFile) {
    throw std::runtime_error("Unable to open file");
  }

  for (DocumentElement *element : doc.getElements()) {

    if (auto *text = dynamic_cast<TextElement *>(element)) {
      outFile << "text\n";
      outFile << text->getText() << "\n";

    } else if (auto *image = dynamic_cast<ImageElement *>(element)) {
      outFile << "image\n";
      outFile << image->getImagePath() << "\n";

    } else {
      throw std::runtime_error("Unknown DocumentElement type");
    }
  }
}