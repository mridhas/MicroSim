#ifndef SOLVERLOOP_H_
#define SOLVERLOOP_H_

void solverloop(long *start, long *end) {
  long x;
  
  calculate_gradients(0, gradient);
  swaplayers();
  calculate_gradients(1, gradient);
  swaplayers();
  
  for(x=start[X]-2; x<=end[X]+2; x++) {
    calculate_gradients(x+1, gradient);    
    calculate_divergence_phasefield(x, gradient);
      
  //Updating concentrations for the layer x-1
    if (x > 1) {
      calculate_fluxes_concentration(x-1, gradient);
      calculate_divergence_concentration(x-1, gradient);
    }
    swaplayers();
  }
}
void solverloop_phasefield(long *start, long *end) {
  long x;
  
  calculate_gradients_phasefield(0, gradient);
  swaplayers();
  calculate_gradients_phasefield(1, gradient);
  swaplayers();
  
  for(x=start[X]-2; x<=end[X]+2; x++) {
    calculate_gradients_phasefield(x+1, gradient);
    calculate_divergence_phasefield(x, gradient);
    swaplayers();
  }
}
void solverloop_concentration(long *start, long *end) {
  long b,k;
  long x;
  long INTERFACE_POS;
  MAX_INTERFACE_POS = 0;
  
  for (b=0; b < NUMPHASES; b++) {
    workers_max_min.rel_change_phi[b] = 0.0;
  }
  for (k=0; k < NUMCOMPONENTS-1; k++) {
    workers_max_min.rel_change_mu[k] = 0.0;
  }
  
  calculate_gradients_concentration(0, gradient);
  swaplayers();
  calculate_gradients_concentration(1, gradient);
  swaplayers();
  
  for(x=start[X]-2; x<=end[X]+2; x++) {
    calculate_gradients_concentration(   x+1, gradient);
    calculate_gradients_phasefield(      x+1, gradient);      
  //Updating concentrations for the layer x-1
    if (x > 1) {
      calculate_fluxes_concentration(    x-1, gradient);
      calculate_divergence_concentration(x-1, gradient);
/***********************************************************************************
// #ifdef SHIFT
//       //Check condition for the shift only for the lowest level
//       INTERFACE_POS = check_SHIFT(x-1);
//       if (INTERFACE_POS > MAX_INTERFACE_POS) {
//         MAX_INTERFACE_POS = INTERFACE_POS;
//       }
// #endif
/*********************************************************************************/
    }
    swaplayers();
  }
}
void  smooth(long *start, long *end) {
  long x;
  
  calculate_gradients(0, gradient);
  swaplayers();
  calculate_gradients(1, gradient);
  swaplayers();
  
  for(x=start[X]-2; x<=end[X]+2; x++) {
    calculate_gradients(x+1, gradient);
    calculate_divergence_phasefield_smooth(x, gradient);
      
  //Updating concentrations for the layer x-1
    if (x > 1) {
      calculate_divergence_concentration_smooth(x-1, gradient);
    }
    swaplayers();
  }
}
void  smooth_concentration(long *start, long *end) {
  long x;
  
  calculate_gradients(0, gradient);
  swaplayers();
  calculate_gradients(1, gradient);
  swaplayers();
  
  for(x=start[X]-2; x<=end[X]+2; x++) {
    calculate_gradients(x+1, gradient);      
  //Updating concentrations for the layer x-1
    if (x > 1) {
      calculate_divergence_concentration_smooth_concentration(x-1, gradient);
    }
    swaplayers();
  }
}
#endif
