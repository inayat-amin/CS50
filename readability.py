letters = 0
words = 0
sentences = 0
text = input("Text: ")
for i in range(len(text)):
    if (text[i].isalpha()):
        letters += 1
    if(text[i] == " " or (i == (len(text) - 1))):
        words += 1
    if(text[i] == "." or text[i] == "!" or text[i] == "?"):
        sentences += 1
        print("Character identified: " + text[i])
print(f"Sentences = {sentences}")
print(f"Letters = {letters}")
print(f"words = {words}")
L = (letters/words)*100
S = (sentences/words)*100
Grade = round(0.0588 * L - 0.296 * S - 15.8)
if (Grade < 1):
    print("Before Grade 1")
elif(Grade > 16):
    print("Grade 16+")
else:
    print(f"Grade: {Grade}")
