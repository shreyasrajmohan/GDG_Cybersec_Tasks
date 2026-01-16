import os
from PIL import Image
from pyzbar.pyzbar import decode

qr_dir = "qr_code_zipbomb"

results = []

for filename in sorted(os.listdir(qr_dir)):
    if not filename.lower().endswith(".png"):
        continue

    path = os.path.join(qr_dir, filename)
    img = Image.open(path)
    decoded = decode(img)

    for d in decoded:
        text = d.data.decode("utf-8")
        results.append((filename, text))
        print(filename, "--->", text)
        '''if text not in list1:
            print(filename, "--->", text)'''

with open("decoded.txt", "w") as f:
    for fn, text in results:
        f.write(f"{fn}: {text}\n")
