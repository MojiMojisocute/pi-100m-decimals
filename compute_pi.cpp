#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#include <cstdio>  

void compute_pi(int decimal_places) {
    int precision = decimal_places * 3.32193;  

    mpf_set_default_prec(precision);

    mpf_t a, b, t, p, pi, a_next, b_next, t_next, temp_t;
    mpf_inits(a, b, t, p, pi, a_next, b_next, t_next, temp_t, NULL);

    mpf_set_d(a, 1.0);
    mpf_sqrt_ui(b, 2);
    mpf_ui_div(b, 1, b);
    mpf_set_d(t, 0.25);
    mpf_set_d(p, 1.0);

    for (int i = 0; i < 20; i++) {
        //a_next = (a + b) / 2
        mpf_add(a_next, a, b);
        mpf_div_ui(a_next, a_next, 2);

        //b_next = sqrt(a * b)
        mpf_mul(b_next, a, b);
        mpf_sqrt(b_next, b_next);

        //t_next = t - p * (a - a_next)^2
        mpf_sub(t_next, a, a_next);
        mpf_mul(t_next, t_next, t_next);
        mpf_mul(t_next, t_next, p);
        mpf_sub(t_next, t, t_next);

        //p = 2 * p
        mpf_mul_ui(p, p, 2);

        mpf_set(a, a_next);
        mpf_set(b, b_next);
        mpf_set(t, t_next);
    }

    //pi = (a + b)^2 / (4 * t)
    mpf_add(pi, a, b);
    mpf_mul(pi, pi, pi);

    //temp_t = 4 * t 
    mpf_mul_ui(temp_t, t, 4);
    mpf_div(pi, pi, temp_t);

    FILE *outfile = fopen("pi_output.txt", "w"); 
    if (outfile) {
        fprintf(outfile, "Pi = ");
        gmp_fprintf(outfile, "%.*Ff\n", decimal_places, pi); 
        fclose(outfile);
    } else {
        std::cout << "Unable to open file\n";
    }

    mpf_clears(a, b, t, p, pi, a_next, b_next, t_next, temp_t, NULL);
}

int main() {
    int decimal_places;
    std::cout << "Enter the number of decimal places for Pi: ";
    std::cin >> decimal_places;

    compute_pi(decimal_places);
    return 0;
}

