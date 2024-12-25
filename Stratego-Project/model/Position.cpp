#include "./Position.h"


Position::Position(int row, int column):row_{row}, column_{column}  {
}

Position::Position():row_{}, column_{}{}

void Position::setPosition(int row, int column){
    row_ = row;
    column_ = column;
}
