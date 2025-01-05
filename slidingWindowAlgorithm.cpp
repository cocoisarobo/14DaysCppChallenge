 int window = glitchPattern.length();
    int glitchSum = 0;
    int checkStream = 0;

    if(videoStream.length() < window) return false;

    for (int i = 0; i < window; i++) {
    glitchSum += glitchPattern[i];
    checkStream += videoStream[i];
    }

    if (checkStream == glitchSum) {
        return true;
    }

    for(int i = 0; i < (videoStream.length()-window); i++){
        checkStream -= videoStream[i];
        checkStream += videoStream[i+window];

        if(checkStream == glitchSum){
            return true;
        }
    }

    return false;
