#include <gtest/gtest.h>
#include <sstream>
#include "../inc/postal_office.h"

TEST(POST_Test, PostalOfficeConstruct)
{
  PostalOffice office("address", "9 am - 10 pm", "mail");
  EXPECT_TRUE(office.getAddress() == "address");
  EXPECT_TRUE(office.getOpeningHours() == "9 am - 10 pm");
  EXPECT_TRUE(office.getService() == "mail");
}

TEST(POST_Test, ClientFun)
{
  Customer customer("Name", "address", "375xxxx", "mail@mail.com", 1, "220116");
  EXPECT_TRUE(customer.getName() == "Name");
  EXPECT_TRUE(customer.getAddress() == "address");
  EXPECT_TRUE(customer.getPhoneNumer() == "375xxxx");
  EXPECT_TRUE(customer.getMail() == "mail@mail.com");
  EXPECT_TRUE(customer.getPostcode() == "220116");
  EXPECT_EQ(customer.getClientID(), 1);
}
TEST(POST_Test, PostmanFun)
{
  Sorter sorter("Name", "address", "375xxxx", "mail@mail.com", 1000);
  EXPECT_TRUE(sorter.getName() == "Name");
  EXPECT_TRUE(sorter.getAddress() == "address");
  EXPECT_TRUE(sorter.getPhoneNumer() == "375xxxx");
  EXPECT_TRUE(sorter.getMail() == "mail@mail.com");
  EXPECT_EQ(sorter.getSalary(), 1000);
}

TEST(POST_Test, DeliveryAddressFun)
{
  DeliveryAddress address;
  address.setDeliveryAddress("220116", "Address");
  EXPECT_TRUE(address.getAddress() == "Address");
  EXPECT_TRUE(address.getPostcode() == "220116");
}

TEST(POST_Test, LetterFun)
{
  Customer sender("Name", "address", "375xxxx", "mail@mail.com", 1, "220116");
  Customer recipient("Name", "address", "375xxxx", "mail@mail.com", 2, "220116");
  Letter letter(sender, recipient, 100.2, "China", "Text");
  EXPECT_TRUE(letter.getLocation() == "China");
  letter.setLocation("Belarus");
  EXPECT_TRUE(letter.getLocation() == "Belarus");
  letter.setOnPostOffice(false);
  EXPECT_FALSE(letter.getOnPostOffice());
}

TEST(POST_Test, ParcelFun)
{
  Customer sender("Name", "address", "375xxxx", "mail@mail.com", 1, "220116");
  Customer recipient("Name", "address", "375xxxx", "mail@mail.com", 2, "220116");
  Parcel parcel(sender, recipient, 100.2, "China", 10.2, 13, 45);
  EXPECT_DOUBLE_EQ(parcel.weight, 100.2);
  EXPECT_TRUE(parcel.getLocation() == "China");
  parcel.setLocation("Belarus");
  EXPECT_TRUE(parcel.getLocation() == "Belarus");
  parcel.setOnPostOffice(false);
  EXPECT_FALSE(parcel.getOnPostOffice());
}

TEST(POST_Test, functional)
{
  PostalOffice office("Belarus", "9 am - 10 pm", "mail");
  office.loadDate("date.txt");
  EXPECT_EQ(office.getNumberOfClients(), 2);
  EXPECT_EQ(office.getNumberOfPostmans(), 2);
  office.sortPackage();
  EXPECT_EQ(office.getPackageInStock(), 1);
}