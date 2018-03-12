#include "DataType.h"
using ::DataType;

//DataType constructor
DataType::DataType(int value){
  this->value = value;
}

//DataType comparison
Comparison DataType::compareTo(DataType &item){
  
  if (value > item.getValue()){
    return GREATER;
  } 
  else if (value == item.getValue()){
    return EQUAL;
  }
  else if (value < item.getValue()){
    return LESS;
  }

}

//Get Value of DataType
int DataType::getValue() const{
  return value;
}

