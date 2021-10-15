#include <iostream>
#include <fstream>

bool isPng(const std::string &path) {
  std::ifstream currentFile(path.c_str(), std::ios::binary);
  std::string fileType = path.substr(path.length()-4);
  if(fileType != ".png" && fileType != ".PNG") 
    return false;
  char firstByte;
  std::string nextBytes;
  if (currentFile.is_open()) {
    currentFile >> firstByte;
    for(int i = 0; i < 3; ++i) {
      char currByte;
      currentFile >> currByte;
      nextBytes += currByte;
    }
    currentFile.close();
  } else{
    std::cout << "Error: file not found!" << std::endl;
  }
  return (firstByte == -119 && nextBytes == "PNG");
}

int main() {
  std::cout << "Enter the path: ";
  std::string fileName;
  std::cin >> fileName;
  std::cout << (isPng(fileName) ? "This is a .png file" : "It is not a .png file") << std::endl;
}

/*
Разработайте программу, которая получает на вход, в стандартный ввод, путь к файлу. На выходе программа должна определить, 
является ли данный файл PNG-изображением. Данная процедура не просто должна смотреть на расширение файла, но и произвести 
минимальный анализ его внутренностей, в бинарном режиме.

Внутренности валидного бинарного файла начинаются со специального 8-байтового заголовка. Нас будут интересовать первые четыре байта. 
Первый байт всегда имеет значение −119 (число со знаком минус), а следующие — это просто символы ‘P’, ‘N’, ‘G’, расположенные друг за другом. 
Обратите внимание, что все они в верхнем регистре.

По результатам проверки пути и внутренностей требуется сообщить пользователю о результате проверки в стандартный вывод.
*/