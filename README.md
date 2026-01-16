# GDG_Cybersec_Tasks
This repository is for my GDG Cybersecurity Recruitment Tasks.
## Task-1 : 3 Levels
This task is a CTF where the hidden flag was presented in the form of three fragments in three different folders, which were *gdg_part1, gdg_part2, gdg_part3*.

### GDG_PART1
This folder comprised of a .git folder, a python file called app.py, a text file called xotwod.txt and a README.txt text file.
I first went through the README and understood that there's some file or folder that's hidden in this directory.
I then opened the xotwod.txt file and just found some lyrics to Starry Eyes by The Weeknd.
I then opened the app.py in VSCode to check out the contents in it, in which there was something that looked like this:
`totally_real_flag = base64.b64encode(b"oopsies :( not the real flag lol, keep looking!").decode()`
which was obviously just to troll, so I ignore that but something else caught my eye which was:
`secret = "d2FpdCwgd2hhdCBpZiB0aGVyZSBhcmUgaGlkZGVuIGZpbGVzIGluIHRoZSBkaXJlY3Rvcnkgd29haC4uLg=="`
and I was curious, so I wanted to decode it. I observe the two equal to signs at the end which indicates that it is base64 encrypted, so I ran this command in my Kali Linux Terminal:
`echo "d2FpdCwgd2hhdCBpZiB0aGVyZSBhcmUgaGlkZGVuIGZpbGVzIGluIHRoZSBkaXJlY3Rvcnkgd29haC4uLg==" | base64 -d`
which gave me the following as output:
`wait, what if there are hidden files in the directory woah...`
which then confirmed my assumptions.

So I head straight to the .git folder and checked if there's anything in the files present.
As soon as I clicked on the COMMIT_EDITMSG file and went through the file, I understood that there was a commit.txt file in the previous versions which was then deleted.
<img width="689" height="509" alt="image" src="https://github.com/user-attachments/assets/71792e5f-f443-4d43-8422-2944cf6dd6ca" />
I then quickly open my Command Prompt in that directory and do the following:
`git status` to check for deleted files, which then showed two files which were deleted.
In order to restore those files, I then used `git restore --staged decoy.txt` but since it didn't work I used `git restore --worktree decoy.txt` which immediately gave me my file, but it had nothing in it.
<img width="1632" height="897" alt="image" src="https://github.com/user-attachments/assets/e3ab4e32-22d0-4dea-b484-06135fbc3335" />

I then wanted to view the previous versions, so I did `git log` which gave me the following results:
<img width="1296" height="848" alt="image" src="https://github.com/user-attachments/assets/d3ab12ea-2511-4f39-901b-6ead9d04dcd0" />

There! I had my answer! I quickly reset the version by using `git reset --soft <previous Commit ID>` and used `git status` to check if the *config.txt* file was present and there it was.

I then did `git restore --worktree config.txt` which gave me the file and on opening the file I had my first fragment of the flag! 
First Part: *gdg{sw1ss_*
