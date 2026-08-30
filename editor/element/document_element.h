#pragma once

#include <string>

class DocumentElement {
public:
  virtual ~DocumentElement() = default;
  virtual void render() = 0;
};

class TextElement : public DocumentElement {
private:
  std::string text;

public:
  TextElement(const std::string &text);
  void render() override;
  const std::string getText() const;
};

class ImageElement : public DocumentElement {
private:
  std::string imagePath;

public:
  ImageElement(const std::string &path);
  void render() override;
  const std::string getImagePath() const;
};
