void print_boundary_conditions(char *argv[]) {
  char outfile[100];  
  char tmpstr1[100];
  char tmpstr2[100];
  
  FILE *fr;
  
  strcpy(tmpstr2, argv[1]);
  
  strcpy(tmpstr1,strtok(tmpstr2, "."));
  
  sprintf(outfile, "%s.bd", tmpstr1);
  
  fr = fopen(outfile, "w");
  
  PRINT_BOUNDARY_CONDITIONS(fr);
  
  fclose(fr);
}