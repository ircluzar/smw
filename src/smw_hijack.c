double autoincrease = 0.00001;
double multiplier = -1;

int Chance(double percent)			// percent chance of winning
{
  multiplier += autoincrease;

  if (multiplier < 1)
    return 0;

  percent = percent * multiplier;

  double roll = rand() % 1000;		// resolution is 1k
  if (roll < percent) return 1;		// winner
  else return 0;					// loser
}

int Hijack_SmwCopyToVram_ForLoop_VRAM() { return Chance(0.001); }
int Hijack_SmwCopyToVram_ForLoop_SKIP() { return Chance(0.0005); }

int Hijack_SmwCopyToVramPitch32_ForLoop_VRAM() { return Chance(0.001); }
int Hijack_SmwCopyToVramPitch32_ForLoop_SKIP() { return Chance(0.0005); }

int Hijack_SmwCopyToVramLow_ForLoop_VRAM() { return Chance(0.001); }
int Hijack_SmwCopyToVramLow_ForLoop_SKIP() { return Chance(0.0005); }

int Hijack_SmwCopyFromVram_ForLoop_VRAM() { return Chance(0.001); }
int Hijack_SmwCopyFromVram_ForLoop_SKIP() { return Chance(0.0005); }

int Hijack_RtlUpdatePalette_ForLoop_SKIP() { return Chance(0.0005); }
int Hijack_SmwClearVram_ForLoop_SKIP() { return Chance(0.0005); }