// Copyright 2020 Dolbnin Mikhail dolbnin@protonmail.com

#include <iostream>
#include <SelfSharedPtr.hpp>
#include <memory>

int main(){
  int a = 1;
  int b = 2;
  int c = 3;

  {
      int d = 10;
      SelfSharedPtr<int> test(&d);
  }

  SelfSharedPtr<int> test0;

  SelfSharedPtr<int> test1(&a);

  SelfSharedPtr<int> test2(test1);

  SelfSharedPtr<int> test3(std::move(test2));

  test0 = test3;

  SelfSharedPtr<int> test4(&b);
  test0 = test4;

   SelfSharedPtr<int> test5;
   if (!test5){
     std::cout << "yes";
   }

   std::cout << "Test * : " << *test4;

   test0.reset();
   test3.reset(&c);
   std::cout << std::endl << test3.use_count();

   test0.swap(test3);
   test0.use_count();
  return 0;
}
