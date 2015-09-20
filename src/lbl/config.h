#pragma once

#include <fstream>
#include <iostream>
#include <map>

#include <boost/lexical_cast.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/serialization/serialization.hpp>

using namespace std;

namespace oxlm {

enum Activation {
  IDENTITY = 0,
  SIGMOID = 1,
  RECTIFIER = 2,
};

struct ModelData {
  ModelData();

  string      training_file;
  string      alignment_file;
  string      test_file;
  string      test_alignment_file;
  int         iterations;
  int         evaluate_frequency;
  int         minibatch_size;
  int         minibatch_threshold;
  int         instances;
  int         ngram_order;
  int         feature_context_size;
  string      model_input_file;
  string      model_output_file;
  float       l2_lbl;
  float       l2_maxent;
  int         word_representation_size;
  int         threads;
  float       step_size;
  int         classes;
  string      class_file;
  string      tree_file;
  bool        randomise;
  bool        reclass;
  bool        diagonal_contexts;
  bool        uniform;
  bool        pseudo_likelihood_cne;
  bool        mixture;
  bool        lbfgs;
  int         lbfgs_vectors;
  int         test_tokens;
  float       gnorm_threshold;
  float       eta;
  float       multinomial_step_size;
  bool        random_weights;
  int         hash_space;
  bool        count_collisions;
  // Deprecated.
  bool        filter_contexts;
  // Deprecated.
  float       filter_error_rate;
  int         max_ngrams;
  int         min_ngram_freq;
  int         vocab_size;
  int         noise_samples;
  Activation  activation;
  int         source_vocab_size;
  int         source_order;
  int         hidden_layers;

  bool operator==(const ModelData& other) const;

  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version) {
    ar & training_file;
    ar & alignment_file;
    ar & test_file;
    ar & test_alignment_file;
    ar & iterations;
    ar & minibatch_size;
    ar & instances;
    ar & ngram_order;
    ar & feature_context_size;
    ar & model_input_file;
    ar & model_output_file;
    ar & l2_lbl;
    ar & l2_maxent;
    ar & word_representation_size;
    ar & step_size;
    ar & classes;
    ar & class_file;
    ar & tree_file;
    ar & randomise;
    ar & diagonal_contexts;
    ar & hash_space;
    ar & filter_contexts;
    ar & filter_error_rate;
    ar & vocab_size;
    ar & noise_samples;
    ar & activation;
    ar & source_vocab_size;
    ar & source_order;
    ar & hidden_layers;
  }
};

ostream& operator<<(ostream& out, const ModelData& config);

} // namespace oxlm
