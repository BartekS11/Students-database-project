#include <gtest/gtest.h>
#include "student.hpp"
#include "database.hpp"

struct DatabaseTest : ::testing::Test 
{
    Database db;
};

TEST_F(DatabaseTest, Display_Empty_Db) 
{
    auto content = db.showDbContent();
    auto expected = "";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, Display_Non_Empty_Db) 
{
    Student S1 {
        "Adam",
        "Kowalski",
        "ul. Piekna 155",
        24367,
        "12345678901",
        Gender::Male
    };
    db.addStudentToDb(S1);

    auto content = db.showDbContent();
    auto expected = "Adam Kowalski; ul. Piekna 155; 24367; 12345678901; Male ";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, Add_Multiple_Users_To_Db) 
{
    Student S1 {
        "Adam",
        "Kowalski",
        "ul. Piekna 155",
        24367,
        "12345678901",
        Gender::Male
    };
    
    Student S2 {
        "ewa",
        "Nowak",
        "ul. Brzyka 1",
        64421,
        "64215785246",
        Gender::Male
    };
    
    db.addStudentToDb(S1);
    db.addStudentToDb(S2);
    auto content = db.showDbContent();
    auto expected = "Adam Kowalski; ul. Piekna 155; 24367; 12345678901; Male ewa Nowak; ul. Brzyka 1; 64421; 64215785246; Male ";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, Sorted_Users_By_First_Name) 
{
    Student S1 {
        "Oliwia",
        "Kowalski",
        "ul. Piekna 155",
        24367,
        "12345678901",
        Gender::Male
    };
    
    Student S2 {
        "Ewa",
        "Nowak",
        "ul. Brzyka 1",
        64421,
        "64215785246",
        Gender::Male
    };
    
    db.addStudentToDb(S1);
    db.addStudentToDb(S2);
    auto content = db.showSortedStudentsByFirstName();
    auto expected = "Ewa Nowak; ul. Brzyka 1; 64421; 64215785246; Male Oliwia Kowalski; ul. Piekna 155; 24367; 12345678901; Male ";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, Sorted_Users_By_PESEL_Number) 
{
    Student S1 {
        "Oliwia",
        "Kowalski",
        "ul. Piekna 155",
        24367,
        "64215785246",
        Gender::Male
    };
    
    Student S2 {
        "Ewa",
        "Nowak",
        "ul. Brzyka 1",
        64421,
        "12345678901",
        Gender::Male
    };
    
    db.addStudentToDb(S1);
    db.addStudentToDb(S2);
    auto content = db.showSortedStudentsByPESELNumber();
    auto expected = "Ewa Nowak; ul. Brzyka 1; 64421; 12345678901; Male Oliwia Kowalski; ul. Piekna 155; 24367; 64215785246; Male ";
    EXPECT_EQ(content, expected);
}