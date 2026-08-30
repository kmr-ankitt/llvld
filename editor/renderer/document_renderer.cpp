#include "document_renderer.h"
#include <vector>

DocumentRenderer::DocumentRenderer(DocumentModel* model)
    : model(model) {
}

void DocumentRenderer::render() {
  std::vector<DocumentElement*> elements = model->getElements();

  for(DocumentElement* element: elements){
    element->render();
  }
}