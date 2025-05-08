package com.example.databaseexample;

import android.app.Activity;
import android.database.Cursor;
import android.os.Bundle;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.TextView;

public class MainActivity extends Activity {

    DatabaseHelper myDB;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        myDB = new DatabaseHelper(this, "app");
        setContentView(R.layout.activity_main);
    }

    public void doList(View v) {
        LinearLayout layout = findViewById(R.id.mainView);
        Cursor cursor = myDB.doQuery("SELECT name, age FROM students");
        if (cursor != null) {
            int nameIndex = cursor.getColumnIndex("name");
            int ageIndex = cursor.getColumnIndex("age");
            while (cursor.moveToNext()) {
                String name = (nameIndex != -1) ? cursor.getString(nameIndex) : "Name not found";
                int age = (ageIndex != -1) ? cursor.getInt(ageIndex) : -1;
                TextView textView = new TextView(this);
                textView.setText("Name: " + name + ", Age: " + age);
                layout.addView(textView);
            }
            cursor.close();
        } else {
            // Handle null cursor
            TextView textView = new TextView(this);
            textView.setText("No data available.");
            layout.addView(textView);
        }
    }

    public void doInsert(View v) {
        TextView nameInput = findViewById(R.id.nameInput);
        TextView ageInput = findViewById(R.id.ageInput);
        String name = nameInput.getText().toString();
        String age = ageInput.getText().toString();
        String[] values = {name, age};
        myDB.doUpdate("INSERT INTO students(name, age) VALUES (?, ?);", values);
        nameInput.setText("");
        ageInput.setText("");
    }

    public void doQuery(View v) {
        Cursor cursor = myDB.doQuery("SELECT name, age FROM students");
        if (cursor != null) {
            int nameIndex = cursor.getColumnIndex("name");
            int ageIndex = cursor.getColumnIndex("age");
            while (cursor.moveToNext()) {
                String name = (nameIndex != -1) ? cursor.getString(nameIndex) : "Name not found";
                int age = (ageIndex != -1) ? cursor.getInt(ageIndex) : -1;
                System.out.println("Name: " + name + ", Age: " + age);
            }
            cursor.close();
        } else {
            // Handle null cursor
            System.out.println("No data available.");
        }
    }
}
