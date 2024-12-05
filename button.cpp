#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pen {
public:
    string color;
    int thickness;
    string type;

    void Draw() {
        cout << "Рисование контура: " << endl;
        cout << "Цвет: " << color << endl;
        cout << "Толщина: " << thickness << endl;
        cout << "Тип: " << type << endl;
    }
};

class Brush {
public:
    string color;

    void Fill() {
        cout << "Заливка: " << endl;
        cout << "Цвет: " << color << endl;
    }
};

class SolidBrush : public Brush {
};

class GradientBrush : public Brush {
public:
    vector<string> colors;
};

class LinearGradientBrush : public GradientBrush {
};

class RadialGradientBrush : public GradientBrush {
};

class HatchBrush : public Brush {
public:
    string secondColor;
    string patternType;
};

class TextureBrush : public Brush {
public:
    string imagePath;
};

class VisualBrush : public Brush {
public:
    string controlId;
};

class Geometry {
public:
    string rep;
    Brush* brush;

    Geometry(const string& rep, Brush* brush) : rep(rep), brush(brush) {}
};

class Rectangle : public Geometry {
public:
    Rectangle(const string& rep, Brush* brush) : Geometry(rep, brush) {}
};

class Ellipse : public Geometry {
public:
    Ellipse(const string& rep, Brush* brush) : Geometry(rep, brush) {}
};

class Polyline : public Geometry {
public:
    Polyline(const string& rep, Brush* brush) : Geometry(rep, brush) {}
};

class Font {
public:
    int fontSize;
    string fontFamily;
    bool bold;
    bool italic;
    bool underline;
    string fontColor;

    Font(int fontSize, const string& fontFamily, bool bold, bool italic, bool underline, const string& fontColor)
        : fontSize(fontSize), fontFamily(fontFamily), bold(bold), italic(italic), underline(underline), fontColor(fontColor) {}
};

class ButtonWithText : public Button, public TextBox {
public:
    ButtonWithText(const string& rep, Brush* brush, int fontSize, const string& fontFamily, bool bold, bool italic, bool underline,
                   const string& fontColor, const string& buttonText, const string& text)
        : Button(rep, brush, fontSize, fontFamily, bold, italic, underline, fontColor, buttonText),
          TextBox(text, Font(fontSize, fontFamily, bold, italic, underline, fontColor)) {}
    void Display() {
        cout << "Кнопка с текстом:" << endl;
        cout << "Текст кнопки: " << Button::text << endl;
        Button::Display();
        TextBox::Display();
    }
};

    void Display() {
        cout << "Кнопка:" << endl;
        cout << "Текст: " << text << endl;
        Rectangle::rep = "Прямоугольник";
        Rectangle::brush->color = "Красный";
        Rectangle::brush->Fill();
        cout << "Шрифт:" << endl;
        cout << "Размер: " << fontSize << endl;
        cout << "Семейство: " << fontFamily << endl;
        cout << "Жирный: " << (bold ? "Да" : "Нет") << endl;
        cout << "Курсив: " << (italic ? "Да" : "Нет") << endl;
        cout << "Подчеркнутость: " << (underline ? "Да" : "Нет") << endl;
        cout << "Цвет: " << fontColor << endl;
    }
};

int main() {
    SolidBrush solidBrush;
    solidBrush.color = "Синий";

    LinearGradientBrush linearGradientBrush;
    linearGradientBrush.color = "Красный";
    linearGradientBrush.colors.push_back("Желтый");
    linearGradientBrush.colors.push_back("Зеленый");

    Font font(12, "Arial", true, false, true, "Черный");

    Button button("Кнопка", &solidBrush, font.fontSize, font.fontFamily, font.bold,      font.italic, font.underline, font.fontColor, "Нажми меня");

    button.Display();
    Font font(12, "Arial", true, false, true, "Черный");

    ButtonWithText buttonWithText("Кнопка с текстом", &solidBrush, font.fontSize,        font.fontFamily, font.bold, font.italic,
                                         font.underline, font.fontColor, "Нажми          меня", "Дополнительный текст");

        buttonWithText.Display();

        return 0;
    }
}
