#pragma once
#include "../model/document.h"

class DocumentRenderer {
private:
  DocumentModel *model;

public:
  explicit DocumentRenderer(DocumentModel* model);
  
  void render();
};
