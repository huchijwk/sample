// Copyright 2018 Minkyu Jo

#include "typing_machine.h"
#include "typing_machine_test.h"
#include "test.h"

class TmConstructorTestSuite
{
private:
  static void BarSeparatorTest() {
    TypingMachine tm;
    ASSERT_EQ(tm.Print('|'), std::string("|"));
  }

  static void BlankSeparatorTest() {
    TypingMachine tm;
    ASSERT_EQ(tm.Print(' '), std::string(" "));
  }

  static void NullSeparatorTest() {
    TypingMachine tm;
    ASSERT_EQ(tm.Print(0), std::string(""));
  }

  static void HomeKeyTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    ASSERT_EQ(tm.Print('|'), std::string("A|"));
    tm.TypeKey('B');
    ASSERT_EQ(tm.Print('|'), std::string("AB|"));
    tm.HomeKey();
    ASSERT_EQ(tm.Print('|'), std::string("|AB"));
  }

  static void EndKeyTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    ASSERT_EQ(tm.Print('|'), std::string("A|"));
    tm.TypeKey('B');
    ASSERT_EQ(tm.Print('|'), std::string("AB|"));
    tm.HomeKey();
    ASSERT_EQ(tm.Print('|'), std::string("|AB"));
    tm.EndKey();
    ASSERT_EQ(tm.Print('|'), std::string("AB|"));
  }

  static void LeftKeyTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    ASSERT_EQ(tm.Print('|'), std::string("A|"));
    tm.LeftKey();
    ASSERT_EQ(tm.Print('|'), std::string("|A"));
  }

  static void LeftKeyTestNegative() {
    TypingMachine tm;
    tm.LeftKey();
    ASSERT_EQ(tm.Print('|'), std::string("|"));
  }

  static void RightKeyTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    ASSERT_EQ(tm.Print('|'), std::string("A|"));
    tm.LeftKey();
    ASSERT_EQ(tm.Print('|'), std::string("|A"));
    tm.RightKey();
    ASSERT_EQ(tm.Print('|'), std::string("A|"));
  }

  static void RightKeyTestNegative() {
    TypingMachine tm;
    tm.RightKey();
    ASSERT_EQ(tm.Print('|'), std::string("|"));
  }

  static void TypeKeyTest() {
    TypingMachine tm;
    std::string msg = "|";
    int i = 0;
    for (char c = 32; c <= 126; c++) {
      ASSERT_TRUE(tm.TypeKey(c));
      msg.insert(i++, 1, c);
      ASSERT_EQ(tm.Print('|'), msg);
    }
  }

  static void TypeKeyOutOfLowerBoundTest() {
    TypingMachine tm;
    for (char c = 0; c < 32; c++) {
      ASSERT_FALSE(tm.TypeKey(c));
      ASSERT_EQ(tm.Print('|'), std::string("|"));
    }
  }

  static void TypeKeyOutOfUpperBoundTest() {
    TypingMachine tm;
    ASSERT_FALSE(tm.TypeKey(127));
    ASSERT_EQ(tm.Print('|'), std::string("|"));
  }

  static void EraseKeyTest() {
    TypingMachine tm;
    tm.TypeKey('A');
    ASSERT_EQ(tm.Print('|'), std::string("A|"));
    ASSERT_TRUE(tm.EraseKey());
    ASSERT_EQ(tm.Print('|'), std::string("|"));
  }

  static void EraseKeyTestNegative() {
    TypingMachine tm;
    ASSERT_FALSE(tm.EraseKey());
    ASSERT_EQ(tm.Print('|'), std::string("|"));
  }

public:
  static void RunTest() {
    BarSeparatorTest();
    BlankSeparatorTest();
    NullSeparatorTest();
    HomeKeyTest();
    EndKeyTest();
    LeftKeyTest();
    LeftKeyTestNegative();
    RightKeyTest();
    RightKeyTestNegative();
    TypeKeyTest();
    TypeKeyOutOfLowerBoundTest();
    TypeKeyOutOfUpperBoundTest();
    EraseKeyTest();
    EraseKeyTestNegative();

    // add more..
  }
};

class SomeOtherTestSuite
{
private:

public:
  static void RunTest() {
    // add more..
  }
};

void TypingMachineTest() {
  TmConstructorTestSuite::RunTest();
  // add more..
}