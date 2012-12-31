#define PP '2'
#define ER 1
struct Ddd {
    char Thost[22] thost;
}

class Shape {
public:
  Shape() {
    nshapes++;
  }
  virtual ~Shape() {
    nshapes--;
  };
  static int nshapes;
};
