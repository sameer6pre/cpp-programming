
void Logic() {
	const int MAX_TAIL = 100;
	// PRECOGS_FIX: clamp nt to valid bounds to prevent out-of-bounds access
	if (nt < 0) nt = 0;
	if (nt > MAX_TAIL) nt = MAX_TAIL;

	int prevx = x;
	int prevy = y;
	int prev2x, prev2y;
	tx[0] = x;
	ty[0] = y;
	for (int i = 1; i < nt; i++) {
		prev2x = tx[i];
		prev2y = ty[i];
		tx[i] = prevx;
		ty[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
	}


	switch (dir)
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;

	default:
		break;
	}
	if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= height) y = 0; else if (y < 0) y = height - 1;

	// Use bounded tailCount for collision checks
	int tailCount = nt;
	if (tailCount < 0) tailCount = 0;
	if (tailCount > MAX_TAIL) tailCount = MAX_TAIL;
	for (int i = 0; i < tailCount; i++) {
		if (tx[i] == x && ty[i] == y) {
			lostgame();
		}

	}

	if (x == fx && y == fy) {
		score += 1;
		if (nt < MAX_TAIL) nt++; // PRECOGS_FIX: only increase nt if capacity allows
		fx = rand() % width;
		fy = rand() % height;
	}
}