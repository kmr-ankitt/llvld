#include "element/document_element.h"

int main(){
    DocumentElement* image = new ImageElement("/home/ankit/Pictures/hank.jpg");
    image->render();
}
