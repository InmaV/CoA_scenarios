# Fetal coarctation of the aorta model

[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.14826951.svg)](https://doi.org/10.5281/zenodo.14826951)
[![License: GPL-2.0-or-later](https://img.shields.io/badge/License-GPL--2.0--or--later-blue.svg)](LICENSE)

This repository contains a closed-loop, lumped-parameter (0D) model of the fetal cardiovascular system developed to investigate the hemodynamic adaptations associated with **coarctation of the aorta (CoA)**.

The model was used to assess how different combinations of:

- aortic isthmus (AoI) narrowing,
- right-to-left ventricular disproportion, and
- ductus arteriosus (DA) dilation

can preserve fetal blood pressures, organ perfusion, and wall shear stress despite increasing CoA severity. The repository includes the cardiovascular model, simulation and post-processing scripts, notebooks for the combined-defect analysis, and the supplementary datasets used in the study.

> **Research use only.** This model is intended for scientific research and methodological development. It is not a medical device and must not be used for clinical diagnosis or treatment decisions.

## Repository structure

| File or directory | Description |
|---|---|
| `FETAL_MODEL_CoA32.cellml` | CellML implementation of the 32-week fetal cardiovascular model. |
| `FETAL_MODEL_CoA.c` | C representation of the fetal CoA model. |
| `solver/` | Files used by the numerical solver. |
| `CoA_simulation.py` | Python script used to configure and run CoA simulations. |
| `functions_to_import_CoA.py` | Helper functions used by the simulation and analysis workflow. |
| `CoA_combined_defects.ipynb` | Notebook for generating and analysing combinations of AoI narrowing, ventricular disproportion, and DA dilation. |
| `Read_results.ipynb` | Notebook for reading, post-processing, and visualising simulation results. |
| `Dataset_S1.xlsx` | Clinical data and measurements from real CoA cases. |
| `Dataset_S2.csv` | Doppler velocities from healthy clinical cases. |
| `LICENSE` | GNU General Public License, version 2 or any later version. |


## Simulated CoA remodeling

The computational experiments examine the interaction between three principal features:

### Aortic isthmus narrowing

The AoI diameter is progressively reduced to represent increasing degrees of CoA severity.

### Ventricular disproportion

Right-to-left ventricular end-diastolic volume disproportion is introduced to reproduce the right-dominant remodeling frequently observed in fetal CoA.

### Ductus arteriosus dilation

The DA diameter is increased to evaluate its compensatory contribution to maintaining downstream perfusion and physiological hemodynamics.

The model can be used to identify combinations of these adaptations that maintain pressures, flows, and wall shear stresses within predefined physiological limits.

## Data and outputs

The repository contains supplementary datasets associated with the model assessment and study results. Consult the accompanying publication and dataset documentation before reusing these files, particularly for:

- cohort definitions,
- variable names and units,
- control and CoA group classifications, and
- interpretation of missing or derived values.

Simulation outputs may include time-dependent pressure and flow waveforms as well as cycle-averaged or derived quantities. Generated result files should not be assumed to be patient-specific unless the model has been explicitly calibrated for that purpose.

## Reproducibility notes

For reproducible analyses:

- run the notebooks from the repository root;
- retain the original CellML, C, and solver files together;
- document any changes to model parameters or physiological thresholds;
- record the Python version and installed package versions; and
- cite the archived Zenodo release rather than only the evolving GitHub repository.

## Citation

When using this repository, please cite both the archived model and the associated scientific publication.

### Archived model

> Villanueva, I., Pellisé, A., & Bernardino, G. (2024). *Coarctation of the aorta model*. Zenodo. https://doi.org/10.5281/zenodo.14826951

### Scientific publication

> Villanueva-Baxarias, I., Pellisé-Tintoré, A., Pérez-Rodríguez, M., Nogué, L., Vaziraani, P., Soveral, I., Crispi, F., Gómez, O., Garcia-Canadilla, P., Camara, O., Bijnens, B., & Bernardino, G. (2025). Understanding the hemodynamic changes in fetuses with coarctation of the aorta using a lumped model of fetal circulation. *PLOS Computational Biology, 21*, e1013096. https://doi.org/10.1371/journal.pcbi.1013096

## License

This repository is distributed under the **GNU General Public License version 2, or—at your option—any later version**. See [`LICENSE`](LICENSE) for the complete terms.

## Authors

- Inmaculada Villanueva
- Anna Pellisé
- Gabriel Bernardino

For questions, reproducibility issues, or bug reports, please open an issue in this repository.
