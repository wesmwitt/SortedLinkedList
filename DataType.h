enum Comparison {GREATER, LESS, EQUAL};

class DataType {

  int value;

 public:
  explicit DataType(int value);
  Comparison compareTo(DataType &item);
  int getValue() const;

}; //DataType
