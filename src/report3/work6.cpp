#include <iostream>
#include <type_traits>

using namespace std;

#define print_self ( cout << __PRETTY_FUNCTION__ << endl )

template <class T>
class Matrix {
  public:
    Matrix() { print_self; } //默认构造函数
    Matrix(int, int);   //含参构造函数
    Matrix(const Matrix<T> &);   //拷贝构造函数
    Matrix &operator=(const Matrix &);    //拷贝赋值运算符
    int getRow() const { return row; }
    int getCol() const { return col; }
    T *getPtr() const { return begin_ptr; }
    T &get(int, int) const;   //获取真实位置上元素的值
    Matrix operator+(const Matrix &);
    Matrix &change(int, int); //改变矩阵大小
    Matrix &set() { cin >> *this; return *this; }
    void display() { cout << *this; }
    ~Matrix() { delete[] begin_ptr; print_self; } //析构函数

  private:
    int row = 0;
    int col = 0;
    T *begin_ptr;
    T *temp_ptr;
    Matrix &copy(const Matrix &, int);
};
// 类外成员函数定义...
template <class T>
Matrix<T>::Matrix(int r, int c) {
  print_self;
  row = r;
  col = c;

  temp_ptr = new T[row * col];
  begin_ptr = temp_ptr;
}

template <class T>
Matrix<T>::Matrix(const Matrix& other) {
  print_self;
  if (this != &other) {
    row = other.row;
    col = other.col;

    temp_ptr = begin_ptr = new T[row * col];
    this->copy(other, row * col);
  }
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other) {
  print_self;
  if (this != &other) {
    row = other.getRow();
    col = other.getCol();

    delete[] begin_ptr;
    temp_ptr = begin_ptr = new T[row * col];
    this->copy(other, getRow() * getCol());
  }

  return *this;
}

template <class T>
T& Matrix<T>::get(int real_row, int real_col) const {
  return *(begin_ptr + (real_row - 1) * col + real_col - 1);
}

template <class T>
Matrix<T>& Matrix<T>::copy(const Matrix<T>& other, int len) {
  print_self;
  for (int count = 0; count < len; ++count) {
    *(begin_ptr + count) = *(other.begin_ptr + count);
  }
  return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &other) {
  if (row != other.row || col != other.col) {
    cout << "diffirent size of two matrix !" << endl;
    return *this;
  } else {
    int size = row * col;
    Matrix temp(row, col);

    for (size_t index = 0; index < size; ++index) {
      *(temp.begin_ptr + index) = *(begin_ptr + index) + *(other.begin_ptr + index);
    }
    return temp;
  }
}

template <class T>
Matrix<T>& Matrix<T>::change(int r, int c) {
  row = r;
  col = c;

  delete[] begin_ptr;
  begin_ptr = temp_ptr = new T[row * col];

  return *this;
}

template <typename T>
istream &operator>>(istream &is, Matrix<T> &goal) {
  int size = goal.getRow() * goal.getCol();
  T temp_item;

  cout << "please enter " << goal.getRow() << '*' << goal.getCol()
       << " items to set the matrix..." << endl;
  for (int count = 0; count < size; ++count) {
    is >> temp_item;
    *(goal.getPtr() + count) = temp_item;
  }
  return is;
}

template <typename T>
ostream &operator<<(ostream &os, const Matrix<T> &goal) {
  os << "[ ";
  for (int count_row = 0; count_row < goal.getRow(); count_row++)  {
    os << "[ ";
      for (int count_col = 0; count_col < goal.getCol(); count_col++)  {
        os << goal.get(count_row + 1, count_col + 1) << ' ';
      }
    os << (count_row == goal.getRow() - 1 ? ("] ]\n") : ("]\n  "));
  }
  return os;
}

int main()
{
  Matrix<int> test1(2, 3);
  test1.set();
  Matrix<int> test2(3, 2);
  cin >> test2;
  Matrix<int> test4(2, 3);
  test4 = test1 + (test2.change(2, 3).set());
  test4.display();

  return 0;
}
