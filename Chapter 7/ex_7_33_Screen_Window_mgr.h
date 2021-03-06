#ifndef EX_7_32_SCREEN_WINDOW_MGR_H
#define EX_7_32_SCREEN_WINDOW_MGR_H

#include <iostream>
#include <string>
#include <vector>

class Screen;

class Window_mgr
{
  public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);

  private:
    std::vector<Screen> screens;
};

class Screen 
{
  friend void Window_mgr::clear(ScreenIndex);

public:
  void some_member() const;

private:
  mutable size_t access_ctr;

public:
  typedef std::string::size_type pos; //equivalent using pos = std::string::size_type;
  Screen() = default;
  Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
  Screen(pos ht, pos wd, std::string s);

  char get() const { return contents[cursor]; };
  inline char get(pos ht, pos wd) const;
  Screen &move(pos r, pos c);
  Screen &set(char);
  Screen &set(pos, pos, char);
  Screen &display(std::ostream &os)
  {
    do_display(os);
    return *this; 
  }
  const Screen &display(std::ostream &os) const 
  {
    do_display(os);
    return *this;
  }

  private:
    void do_display(std::ostream &os) const { os << contents; }
    pos size() const;

    pos cursor = 0;       //position of cursor
    pos height = 0;       //height of screen
    pos width = 0;        //width of screen
    std::string contents; //screen's contents
};

Screen::pos Screen::size() const
{
  return height * width;
}

inline void Window_mgr::clear(ScreenIndex i)
{
  Screen &s = screens[i];
  s.contents = std::string(s.height * s.width, ' ');
}

Screen::Screen(pos ht, pos wd, std::string s) : height(ht), width(wd), contents(s)
{
  int space_cnt = 0;
  std::cin >> space_cnt;
  for (int i = 0; i < space_cnt; ++i)
    s[i] = ' ';
}
void Screen::some_member() const
{
  ++access_ctr;
}
char Screen::get(pos r, pos c) const{
  pos row = r * width;
  return contents[row + c];
}
inline Screen &Screen::move(pos r, pos c)
{
  pos row = r * width;
  cursor = row + c;
  return *this;
}
inline Screen &Screen::set(char c)
{
  contents[cursor] = c;
  return *this;
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
  contents[r * width + col] = ch;
  return *this;
}

#endif
