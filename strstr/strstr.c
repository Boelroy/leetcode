int strStr(char* haystack, char* needle) {
    if (haystack == NULL && needle == NULL) return -1;

    int length = strlen(haystack);
    int nlength = strlen(needle);
    if (nlength == 0) return 0;

    for(int j = 0; j < length - nlength + 1; j++) {
        int tmp = j;
        for (int i = 0; i < nlength; i++, tmp++) {
            if (haystack[tmp] == needle[i]) {
                if (i == nlength - 1) return j;
            } else {
                break;
            }
        }
    }
    return -1;
}
