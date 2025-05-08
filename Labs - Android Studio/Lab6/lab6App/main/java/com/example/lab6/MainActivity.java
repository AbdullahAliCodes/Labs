package com.example.lab6;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.io.IOException;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class MainActivity extends AppCompatActivity {
    OkHttpClient client = new OkHttpClient();
    String getURL = "https://lamp.ms.wits.ac.za/home/s2309318/cars.php";
    TextView textView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView = findViewById(R.id.table);
        Button getButton = findViewById(R.id.getbutton);
        Button setButton = findViewById(R.id.setbutton);
        getButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                    get();
            }
        });

    }

    public void get(){
        Request request = new Request.Builder().url(getURL).build();
        client.newCall(request).enqueue(new Callback() {
            @Override
            public void onFailure(@NonNull Call call, @NonNull IOException e) {
                e.printStackTrace();
            }

            @Override
            public void onResponse(@NonNull Call call, @NonNull Response response) throws IOException {
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        try {
                            textView.setText(response.body().string());
                        } catch (IOException e) {
                            throw new RuntimeException(e);
                        }
                    }
                });
            }
        });
    }
}