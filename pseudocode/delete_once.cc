// Part 1
/// Write Delete_Once() using only the basic set 1 operations
void Delete_Once(String& s, char c) {
    int i = 0;
    String replacement;

    while (!Is_Empty(s)) {
        char temp = Delete_At(s, i);
        if (temp != c)
            Append(replacement, temp);

        i++;
    }

    s = replacement;
}

// Part 2
/// Write Delete_Once() using only set 2 operations
void Delete_Once(String& s, char c) {
    int pos = Pos(s, c);
    for (int i = 0; i < Length(s); i++) {
        if (i != pos)
            Append(s, Get_Char(s, i));
    }
}

// Part 3
/// Write Delete_Once() using only set 3 operations
void Delete_Once(String& s, char c) {
    String replacement;
    bool deleted = false;
    int pos = 0;

    while (!Is_Empty(s)) {
        char temp = Delete_First(s);
        if (temp != c || (temp == c && deleted)) {
            Insert_at(s, temp, pos);
            pos++;
        }
        else if (temp == c && !deleted) {
            deleted = true;
        }
    }

    s = replacement;
}
