# GDG_Cybersec_Tasks
This repository is for my GDG Cybersecurity Recruitment Tasks.
## Task-1 : 3 Levels
This task is a CTF where the hidden flag was presented in the form of three fragments in three different folders, which were *gdg_part1, gdg_part2, gdg_part3*.

### GDG_PART1
This folder comprised of a .git folder, a python file called app.py, a text file called xotwod.txt that contains lyrics to the song "Starry Eyes - The Weeknd" and a README.txt text file.
I first went through the README and understood that there's some file or folder that's hidden in this directory.
I then opened the app.py in VSCode to check out the contents in it, in which there was something that looked like this:
```totally_real_flag = base64.b64encode(b"oopsies :( not the real flag lol, keep looking!").decode()```
which was clearly a decoy, so I ignore that but something else caught my eye which was:
```secret = "d2FpdCwgd2hhdCBpZiB0aGVyZSBhcmUgaGlkZGVuIGZpbGVzIGluIHRoZSBkaXJlY3Rvcnkgd29haC4uLg=="```
and I was curious, so I wanted to decode it. I observe the two equal to signs at the end which indicates that it is base64 encoded, so I ran this command in my Kali Linux Terminal:
```echo "d2FpdCwgd2hhdCBpZiB0aGVyZSBhcmUgaGlkZGVuIGZpbGVzIGluIHRoZSBkaXJlY3Rvcnkgd29haC4uLg==" | base64 -d```
which gave me the following as output:
```wait, what if there are hidden files in the directory woah...```
which then confirmed my assumptions.

So I head straight to the .git folder and checked if there's anything in the files present.
As soon as I clicked on the COMMIT_EDITMSG file and went through the file, I understood that there was a commit.txt file in the previous versions which was then deleted.

<img width="450" height="450" alt="image" src="https://github.com/user-attachments/assets/71792e5f-f443-4d43-8422-2944cf6dd6ca" />

I then quickly open my Command Prompt in that directory and do the following:
`git status` to check for deleted files, which then showed two files which were deleted.
In order to restore those files, I then used `git restore --staged decoy.txt` but since it didn't work I used `git restore --worktree decoy.txt` which immediately gave me my file, but it had nothing in it.

<img width="750" height="450" alt="image" src="https://github.com/user-attachments/assets/e3ab4e32-22d0-4dea-b484-06135fbc3335" />

I then wanted to view the previous versions, so I did `git log` which gave me the following results:

<img width="750" height="450" alt="image" src="https://github.com/user-attachments/assets/d3ab12ea-2511-4f39-901b-6ead9d04dcd0" />

There! I had my answer! I quickly reset the version by using `git reset --soft <previous Commit ID>` and used `git status` to check if the *config.txt* file was present and there it was.
I then did `git restore --worktree config.txt` which gave me the file and on opening the file.

<img width="750" height="450" alt="image" src="https://github.com/user-attachments/assets/030d5d8b-d982-45e2-88d1-e2dde50fa44f" />

I had my first fragment of the flag! 
First Part: *gdg{sw1ss_*

### GDG_PART2
This folder comprised of just two files, a README.txt text file and a heheheha.png image.
The image: 

<img width="450" height="450" alt="heheheha" src="https://github.com/user-attachments/assets/5906b3b2-bb5c-4204-874c-47a1b455883c" />

There was nothing special about the image, which is actually the reason for the thought of *image steganography* went past my mind.
I then ran the image through *zsteg* in my KALI Linux System which then threw the output:

<img width="350" height="75" alt="image" src="https://github.com/user-attachments/assets/0e317cda-a794-49f4-b24d-68ee3699f49c" />

The tool immediately identified the hidden data, but here, a confusion arises, is the fragment *10:armykn1f3_* or *armykn1f3_*?
Well, the "10:" in the output is the way zsteg gives the output, its the offset/ID so we exclude it.

Second Part: *armykn1f3_*

### GDG_PART3
This folder comprised of a qr_code_zipbomb.rar compressed file and a README.txt text file.
On reading the README and extraction and inspection of the folder, we can find 3000 QR Codes .png files, each with different codes.
Doing this manually would be such a hassle, thankfully, I already have Pillow and Pyzbar installed in my system.
I then open up VSCode and code the main file extension verification code and the data extraction code and also code to put all the results into a file called decoded.txt text file.

<a href="https://github.com/shreyasrajmohan/GDG_Cybersec_Tasks/blob/main/script.py">View the Automation Script Here!</a>

I then opened this decoded.txt in Notepad++ and use the macro automation to delete all the unnecessary file names and sort only the extracted data.
This data is then carefully examined until I find the anomalous data `PDwtLS0tcGFydDM9Z2cxb2x9LS0tLT4+` on qr_1967.
I then try decoding it using base64, it gave me the following output:

<img width="438" height="61" alt="image" src="https://github.com/user-attachments/assets/45f1933f-ab91-405d-a963-109e757c7910" />

which means,

Third Part: *gg1ol}*

Combining all three parts together, the final flag is 

*```gdg{sw1ss_armykn1f3_gg1ol}```*

### Conclusion
Great challenge. It bridged the gap between theory and practice, forcing me to script my own way out of a mess. I’m walking away with a slight headache, a flag, and much a better approach to coding.


## Task-1B: apple_pi3

This task is a CTF where the flag is hidden within a binary file which is protected with modern security mechanisms and basic obfuscation. This is not just a CTF but we are also asked to analyze the binary and determine whether the hidden data can still be discovered.

### Approach and Process

I opened the binary in Ghidra, a popular reverse engineering tool, which provided decompiled code and a function list in the Symbol Tree window.

<img width="850" height="450" alt="image" src="https://github.com/user-attachments/assets/fe7b8690-71b7-45db-8b93-d00d6ab6c530" />

I then proceeded to view all the functions in the Symbol Tree window and found something suspicious called `def_nothing_important`.

<img width="269" height="216" alt="image" src="https://github.com/user-attachments/assets/d3d01864-73e2-444e-969e-3a975920dac4" />

I realized that this function contained the core obfuscation logic responsible for hiding the flag.

<img width="785" height="450" alt="image" src="https://github.com/user-attachments/assets/465668fd-5225-4172-9b29-439243ca989e" />

After cleaning up and correcting the decompiled C code to make it compilable, I recompiled and executed it, which revealed the flag!

<a href = "https://github.com/shreyasrajmohan/GDG_Cybersec_Tasks/blob/main/applepie.c" >View the corrected C code here!</a>

<img width="850" height="450" alt="image" src="https://github.com/user-attachments/assets/d729490f-d3b0-40e8-9113-58f3a47d2d2c" />

### Result

Flag: ```gdg{P1E_3xpl01ted_lol}```

### Conclusion

This challenge shows that basic obfuscation and modern binary protections are not sufficient to fully hide sensitive data. By analyzing the binary in Ghidra and understanding the obfuscated logic, the hidden flag was successfully recovered. The task reinforces the effectiveness of reverse engineering techniques and the importance of stronger protection methods.
