package com.predo;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Buffered {
    public static void main(String[] args) {
        File fp = new File("buffered.txt");
        try {
            FileWriter fw = new FileWriter(fp);
            BufferedWriter bw = new BufferedWriter(fw);
            bw.write("AAAAAAAAAAAAAAAAAAAAAA");
            bw.flush();
            bw.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
