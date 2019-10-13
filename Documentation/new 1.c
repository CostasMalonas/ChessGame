bool Board::moveRook(Square thisRook, Square thatSpace)
{
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	int rookX = thisRook->getX();
	int rookY = thisRook->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();
	bool invalid = false;
	if (((rookX == thatX) && (rookY != thatY)))//(rookX != thatX || rookY != thatY)
	{
		int yIncrement = (thatY - rookY) / (abs(thatY - rookY));
		for (int i = rookY + yIncrement; i != thatY; i += yIncrement)
		{

			if (square[thatX][i].getColor() != NONE)
				return false;

		}
	}
	else if ((rookY == thatY) && (rookX != thatX))
	{
		int xIncrement = (thatX - rookX) / (abs(thatX - rookX));
		for (int i = rookX + xIncrement; i != thatX; i += xIncrement)
		{
			if (square[i][thatY].getColor() != NONE)
				return false;
		}
	}
	else
		return false;
	thatSpace->setSpace(thisRook);
	thisRook->setEmpty();
	return true;
}