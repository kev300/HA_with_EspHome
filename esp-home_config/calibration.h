float calibrate_segmented_linear(std::vector<std::vector<float>> mapping, float x) {
    float res = x;
    if (x < mapping[0][0]) {
        // Less than mapping
        // Use the left-most pair.
        float before_a = mapping[0][0];
        float after_a = mapping[0][1];
        float before_b = mapping[1][0];
        float after_b = mapping[1][1];
        float before_diff = before_b - before_a;
        float after_diff = after_b - after_a;
        float diff = before_a - x;
        float ratio = diff / before_diff;
        res = after_a - (ratio * after_diff);
    } else if (x > mapping[mapping.size() - 1][0]) {
        // More than mapping
        // Use the right-most pair.
        int i = mapping.size() - 1;
        float before_a = mapping[i-1][0];
        float after_a = mapping[i-1][1];
        float before_b = mapping[i][0];
        float after_b = mapping[i][1];
        float before_diff = before_b - before_a;
        float after_diff = after_b - after_a;
        float diff = x - before_b;
        float ratio = diff / before_diff;
        res = after_b + (ratio * after_diff);
    } else {
        // Within mapping
        // Find and use the pair that x sits between.
        for (int i = 1; i < mapping.size(); i++) {
            float before_a = mapping[i-1][0];
            float after_a = mapping[i-1][1];
            float before_b = mapping[i][0];
            float after_b = mapping[i][1];
            if (x <= before_b) {
                float before_diff = before_b - before_a;
                float after_diff = after_b - after_a;
                float diff = x - before_a;
                float ratio = diff / before_diff;
                res = after_a + (ratio * after_diff);
                break;
            }
        }
    }
    return res;
}
