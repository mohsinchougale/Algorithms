def rabin_karp(pat, txt, q):
    M = len(pat)
    N = len(txt)
    p = 0    # hash value for pattern
    t = 0    # hash value for txt
    h = 1
    flag = 0

    # The value of h would be "pow(d, M-1)%q"
    for i in range(M-1):
        h = (h*d)%q

    print("Hash Values of Pattern:")
    # Calculate the hash value of pattern
    for i in range(M):
        #ord() functions returns the ASCII value
        p = (d*p + ord(pat[i]))%q
        print(pat[i]," = ",ord(pat[i]))
        print("Hash value p = ",p)
        print("\n")

    print("Hash Values of First window of Text:")
    # Calculate the hash value of first window of text
    for i in range(M):
        #ord() functions returns the ASCII value
        t = (d*t + ord(txt[i]))%q
        print(txt[i]," = ",ord(txt[i]))
        print("Hash value t = ",t)
        print("\n")

    print("Hash value text window starting from: ")
    # Slide the pattern over text one by one
    for i in range(N-M+1):
        # Checking if the hash values of current window of text and pattern are equal
        if p==t:
            flag+=1
            print("Hash values matched!")
            # Checking for characters one by one
            for j in range(M):
                if txt[i+j] != pat[j]:
                    break
                else: j+=1

            # if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if j==M:
                print("\nPattern found at index " + str(i))



        # Rolling Hash Function
        if i < N-M:
            t = (d*(t-ord(txt[i])*h) + ord(txt[i+M]))%q


            # We might get negative values of t, converting it to positive
            if t < 0:
                t = t+q

            print(txt[i]," = ",ord(txt[i]))
            print("Hash value t = ",t)
            print("\n")
    if(flag==0):
        print("\nPattern NOT found")



txt = input("Enter text: ")
pat = input("Enter pattern: ")

d = 256
q = 101


rabin_karp(pat,txt,q)
