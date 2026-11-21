#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// useful for manipulation of strings
#include <sstream>

// to set precision when printing
#include <iomanip>

std::vector<double> extract_row(std::vector<std::vector<double>> matrix, int row_idx) {
    std::vector<double> row = matrix[row_idx];
    return row;
}

std::vector<double> extract_column(std::vector<std::vector<double>> matrix, int col_idx) {
    std::vector<double> col;
    for (int i = 0; i < matrix.size(); i++) {
        col.push_back(matrix[i][col_idx]);
    }
    return col;
}

double scalar_product(std::vector<double> row, std::vector<double> col) {
    if (row.size() != col.size()) {
        std::exit(EXIT_FAILURE);
    }
    
    double scalar = 0.0;

    for (int i = 0; i < row.size(); i++) {
        scalar += row[i] * col[i];
    }

    return scalar;
}

std::vector<double> line_to_vector(std::string s){

    std::stringstream ss;
    std::string tmp;
    std::vector<double> out;

    // we can use a stringstream as if it were a stream object 
    // such as std::cout or something of type
    // std::ifstream or std::ofstream

    ss << s;
    while(ss >> tmp){
        // std::stod converts from string to double
        out.push_back(std::stod(tmp));
    }
    return out;
}

std::vector<std::vector<double>> read_matrix_from_file(std::string input_file){

    std::ifstream infile;
    infile.open(input_file);
    if(!infile.is_open()){
        std::cout << "error opening file " << input_file << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string line;
    std::vector<std::vector<double>> out;

    // std::getline reads a whole line as a string
    // by default the separator is the newline
    // rather than any whitespace
    while(std::getline(infile, line)){
        out.push_back(line_to_vector(line));
    }

    return out;
}

std::vector<std::vector<double>> matrix_mul(const std::vector<std::vector<double>>& m1, const std::vector<std::vector<double>>& m2) {
    std::vector<std::vector<double>> out;

    for (int i = 0; i < m1.size(); i++) {

        std::vector<double> out_row;

        std::vector<double> row = extract_row(m1, i);

        for (int j = 0; j < m2[0].size(); j++) {
            std::vector<double> column = extract_column(m2, j);
            out_row.push_back(scalar_product(row, column));
        }

        out.push_back(out_row);
    }

    return out;
}

std::string matrix_to_string(std::vector<std::vector<double>> m){

    std::stringstream out;
    // to set precision when printing
    out << std::fixed << std::setprecision(2);

    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[0].size(); j++){
            out << (m[i][j]) << "\t";
        }
        out << "\n";
    }

    // getting the std::string representation 
    // of this std::stringstream object
    return out.str();
}

int main(int argc, char* argv[]){

    if(argc != 3){
        std::cout << "two arguments needed" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::vector<double>> m1 = read_matrix_from_file(argv[1]);
    std::vector<std::vector<double>> m2 = read_matrix_from_file(argv[2]);

    std::vector<std::vector<double>> m3 = matrix_mul(m1, m2);

    std::cout << matrix_to_string(m1) << std::endl;
    std::cout << "+" << std::endl << std::endl;
    std::cout << matrix_to_string(m2) << std::endl;
    std::cout << "=" << std::endl << std::endl;
    std::cout << matrix_to_string(m3) << std::endl;

}