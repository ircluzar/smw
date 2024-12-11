double autoincrease = 0.00015;
double multiplier = -420.0;

int Chance(double percent)			// percent chance of winning
{
  multiplier += autoincrease;

  if (multiplier < 1)
    return 0;

  if (multiplier > 2000.0)
    multiplier = 2000.0;

  percent = percent * multiplier;

  double roll = (rand() % 1000)/1000.0;		// resolution is 1k
  if (roll < percent) return 1.0;		// winner
  else return 0;					// loser
}
int speedhackTimeout = 0;


void Hijack_TimeoutSpeedHacks() {
  speedhackTimeout = 666;
}

void Hijack_StartNewLevel() {
  multiplier = 1.0;
  autoincrease = autoincrease * 1.05;
}

void Hijack_LevelWin() {
  multiplier = 1;
  speedhackTimeout = 666;
}



int Hijack_UpdatePlayerSpritePosition_SKIP() {
    if (speedhackTimeout > 0)
    {
    speedhackTimeout--;
    return 0;
    }

    return Chance(0.69); 
}
int Hijack_FlagIceLevel_OVERRIDE() { 
        if (speedhackTimeout > 0) {
    speedhackTimeout--;
    return 0;
    }


    return Chance(0.420); 
}
int Hijack_PlayerState0_SKIP() {
    if (speedhackTimeout > 0) {
    speedhackTimeout--;
    return 0;
    }

    return Chance(0.000001); 
}
int Hijack_HandlePlayerPhysics_SKIP() {
    if (speedhackTimeout > 0) {
    speedhackTimeout--;
    return 0;
    }

    return Chance(0.00001);
}

int Hijack_SmwCopyToVram_ForLoop_VRAM() { return Chance(0.0001); }
int Hijack_SmwCopyToVram_ForLoop_SKIP() { return Chance(0.00005); }

int Hijack_SmwCopyToVramPitch32_ForLoop_VRAM() { return Chance(0.0001); }
int Hijack_SmwCopyToVramPitch32_ForLoop_SKIP() { return Chance(0.00005); }

int Hijack_SmwCopyToVramLow_ForLoop_VRAM() { return Chance(0.0001); }
int Hijack_SmwCopyToVramLow_ForLoop_SKIP() { return Chance(0.00005); }

int Hijack_SmwCopyFromVram_ForLoop_VRAM() { return Chance(0.0001); }
int Hijack_SmwCopyFromVram_ForLoop_SKIP() { return Chance(0.00005); }

int Hijack_RtlUpdatePalette_ForLoop_SKIP() { return Chance(0.00005); }
int Hijack_SmwClearVram_ForLoop_SKIP() { return Chance(0.00005); }

int Hijack_SmwSpcPlayer_CopyVariablesToRam_SKIP() { return Chance(0.00005); }
int Hijack_SmwSpcPlayer_CopyVariablesToRam_SKIP2() { return Chance(0.00005); }

int Hijack_SmwSpcPlayer_CopyVariablesFromRam_SKIP() { return Chance(0.00005); }
int Hijack_SmwSpcPlayer_CopyVariablesFromRam_SKIP2() { return Chance(0.00005); }
int Hijack_SmwSpcPlayer_PlayNote_SKIP() { return Chance(0.00005); }
int Hijack_SmwSpcPlayer_Music_Process_SKIP() { return Chance(0.0005); }

int Hijack_SmwSpcPlayer_PlayNote_Drift1() { return Chance(0.0069); }
int Hijack_SmwSpcPlayer_PlayNote_Drift2() { return Chance(0.0069); }
int Hijack_SmwSpcPlayer_PlayNote_Drift3() { return Chance(0.0069); }
int Hijack_SmwSpcPlayer_PlayNote_Drift4() { return Chance(0.0069); }
int Hijack_SmwSpcPlayer_PlayNote_Drift5() { return Chance(0.0069); }
int Hijack_SmwSpcPlayer_PlayNote_Drift6() { return Chance(0.0069); }