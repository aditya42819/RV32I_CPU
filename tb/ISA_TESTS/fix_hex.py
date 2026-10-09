import re

input_file = 'test_rv32i_full.hex'
output_file = 'test_rv32i_full_clean.hex'

print(f"Processing {input_file}...")

with open(input_file, 'r') as f_in, open(output_file, 'w') as f_out:
    for line in f_in:
        line = line.strip()
        if not line:
            continue
        
        # Keep the memory address header exactly as is
        if line.startswith('@'):
            f_out.write(line + '\n')
        else:
            # Remove ALL whitespace (spaces, tabs, etc.)
            clean_line = re.sub(r'\s+', '', line)
            
            # Process in 8-character chunks (32-bit words)
            for i in range(0, len(clean_line), 8):
                word = clean_line[i:i+8]
                if len(word) == 8:
                    # Reverse byte order (Little Endian to Big Endian Word)
                    # e.g., '37150000' -> '00001537'
                    b0 = word[0:2]
                    b1 = word[2:4]
                    b2 = word[4:6]
                    b3 = word[6:8]
                    f_out.write(f"{b3}{b2}{b1}{b0}\n")

print(f"Done! Cleaned file saved as {output_file}")